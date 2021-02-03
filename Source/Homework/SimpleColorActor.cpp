// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleColorActor.h"

// Sets default values
ASimpleColorActor::ASimpleColorActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    //RootComponent = StaticMeshComponent;
    StaticMeshComponent->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ASimpleColorActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ASimpleColorActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //StaticMeshComponent->AddRelativeRotation(FRotator(0.f, 0.f, 1.f));

    FLinearColor Color;
	Color.R = (((CurrentColor) & (1 << static_cast<uint32>(EColor::Red))) > 0) ? 1.0f : 0.0f;
	Color.G = (((CurrentColor) & (1 << static_cast<uint32>(EColor::Green))) > 0) ? 1.0f : 0.0f;
	Color.B = (((CurrentColor) & (1 << static_cast<uint32>(EColor::Blue))) > 0) ? 1.0f : 0.0f;
    StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), FVector(Color.R, Color.G, Color.B));
}

void ASimpleColorActor::Hold_Implementation(USceneComponent* SceneObject)
{
	bIsGripped = true;
	Hand = SceneObject;
	auto strictRules = FAttachmentTransformRules(EAttachmentRule::KeepWorld, true);
	AttachToComponent(SceneObject, strictRules);
}

void ASimpleColorActor::Drop_Implementation()
{
	StaticMeshComponent->SetSimulatePhysics(true);
	bIsGripped = false;
	Hand = nullptr;
	auto rules = FDetachmentTransformRules(EDetachmentRule::KeepWorld, true);
	DetachFromActor(rules);
}

void ASimpleColorActor::Throw_Implementation()
{
	//this->Throw();
	StaticMeshComponent->SetSimulatePhysics(true);
	bIsGripped = false;
	FVector forward_vec = Hand->GetForwardVector();
	Hand = nullptr;
	auto rules = FDetachmentTransformRules(EDetachmentRule::KeepWorld, true);
	DetachFromActor(rules);
	
	StaticMeshComponent->AddImpulse(forward_vec * StaticMeshComponent->GetMass() * 1000, NAME_None, false);
	//StaticMeshComponent->AddImpulseAtLocation(forward_vec * 5000, FVector(0.0f, 0.0f, 0.0f), NAME_None);
}
