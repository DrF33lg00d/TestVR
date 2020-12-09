// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "SimpleColorActor.generated.h"

UENUM()
enum class EColor : uint8 {
	Red,
	Green,
	Blue
};


UCLASS()
class HOMEWORK_API ASimpleColorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASimpleColorActor();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	EColor CurrentColor;

	virtual void Tick(float DeltaTime) override;
		
protected:
	virtual void BeginPlay() override;

};
