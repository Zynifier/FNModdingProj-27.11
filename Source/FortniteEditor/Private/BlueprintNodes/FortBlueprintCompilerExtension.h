// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintCompilerExtension.h"
#include "FortBlueprintCompilerExtension.generated.h"

class UObject;

UCLASS(Abstract)
class UFortBlueprintCompilerExtension : public UBlueprintCompilerExtension
{
	GENERATED_BODY()

public:
	UFortBlueprintCompilerExtension(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Transient)
	TObjectPtr<UObject> GameplayTagSubcategoryObject;

	UPROPERTY(Transient)
	TObjectPtr<UObject> GameplayTagContainerSubcategoryObject;

};

