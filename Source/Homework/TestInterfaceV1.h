// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TestInterfaceV1.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTestInterfaceV1 : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HOMEWORK_API ITestInterfaceV1
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Test_Hold")
		void Hold(USceneComponent* SceneObject);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Test_Drop")
		void Drop();
};
