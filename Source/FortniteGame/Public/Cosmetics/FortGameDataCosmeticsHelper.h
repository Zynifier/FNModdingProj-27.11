// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortGameDataCosmeticsHelper.generated.h"

class UAthenaCharacterItemDefinition;
class UObject;
enum class EDefaultCharacterSelection : uint8;

UENUM()
enum class EDefaultCharacterSelection : uint8
{
	Random = 0,
	// Randomly pick a character

	DefaultBase = 1,
};

UCLASS()
class UFortGameDataCosmeticsHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContext"))
	static UAthenaCharacterItemDefinition* GetGameDefaultOutfit(UObject* WorldContext, EDefaultCharacterSelection Selection);

};

