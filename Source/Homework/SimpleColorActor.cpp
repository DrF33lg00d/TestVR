// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleColorActor.h"

// Sets default values
ASimpleColorActor::ASimpleColorActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    RootComponent = StaticMeshComponent;
    StaticMeshComponent->SetSimulatePhysics(true);
    StaticMeshComponent->SetMassOverrideInKg(NAME_None, Mass);
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

    FVector Color(0.f, 0.f, 0.f);
    switch (CurrentColor)	{
	    case EColor::Red:
		    Color.X = 1.f;
		    break;
	    case EColor::Green:
		    Color.Y = 1.f;
		    break;
	    case EColor::Blue:
		    Color.Z = 1.f;
		    break;
    }
    StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), Color);
}

void ASimpleColorActor::Hold_Implementation(USceneComponent* SceneObject)
{
	//StaticMeshComponent->SetSimulatePhysics(false);
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
