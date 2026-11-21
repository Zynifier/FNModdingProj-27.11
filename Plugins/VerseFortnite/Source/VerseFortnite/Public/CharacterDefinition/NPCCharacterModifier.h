// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/UObjectGlobals.h"
#include "NPCCharacterModifier.generated.h"

class AFortPawn;
class UFortAthenaAISpawnerDataComponentList;
class UNPCCharacterDefinition;
class UObject;

UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable, meta=(DisplayName="NPC Character Modifier"))
class VERSEFORTNITE_API UNPCCharacterModifier : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, meta=(CallInEditor="true"))
	EDataValidationResult BP_IsDataValid(TArray<FText>& OutErrorMessages) const;

	UFUNCTION(BlueprintNativeEvent)
	bool BP_IsNeededForPreview() const;

	UFUNCTION(BlueprintNativeEvent)
	void BP_ModifySpawnComponentList(UFortAthenaAISpawnerDataComponentList* OutList, UObject* ComponentOuter);

	UFUNCTION(BlueprintNativeEvent)
	void BP_OnPreSpawned(AFortPawn* Pawn);

	UFUNCTION(BlueprintNativeEvent)
	void BP_OnSpawned(AFortPawn* Pawn);

	UFUNCTION(BlueprintPure)
	UNPCCharacterDefinition* GetCharacterDefinition() const;

};

