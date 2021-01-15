// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
//#include "TestInterfaceV1.h"
#include "SimpleColorActor.generated.h"

UENUM()
enum class EColor : uint8 {
	Red,
	Green,
	Blue
};


UCLASS()
class HOMEWORK_API ASimpleColorActor : public AActor//, public ITestInterfaceV1
{
	GENERATED_BODY()
	
public:	
	ASimpleColorActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
		EColor CurrentColor;

	UPROPERTY(EditAnywhere)
		float Mass;

	virtual void Tick(float DeltaTime) override;

	/*UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Test_Hold")
		void Hold(USceneComponent* SceneObject);*/
	virtual void Hold(USceneComponent* SceneObject);

	/*UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Test_Drop")
		void Drop();*/
	virtual void Drop();

	bool bIsGripped = false;
		
protected:
	virtual void BeginPlay() override;

	USceneComponent* Hand = nullptr;
};
