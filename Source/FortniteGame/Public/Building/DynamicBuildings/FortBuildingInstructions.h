// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortZoneRecord.h"
#include "Physics/FortPhysicsObjectComponent.h"
#include "FortBuildingInstructions.generated.h"

class ABuildingActor;
class UFortBuildingInstructionModifier;
class UWorld;

USTRUCT(BlueprintType)
struct FFortBuildingInstruction
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="ActorRecord")
	FFortActorRecord ActorRecord;

};

USTRUCT()
struct FModifierPhysicsObjectSetupData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ModifierPhysicsObjectSetupData", meta=(AllowAbstract="TRUE"))
	TSoftClassPtr<ABuildingActor> BuildingClassToSetup;

	UPROPERTY(EditAnywhere, Category="ModifierPhysicsObjectSetupData")
	FPhysicsObjectSetupTags PhysicsObjectSetupTags;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI)
class UFortBuildingInstructionModifier : public UObject
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType)
class UFortBuildingInstructions : public UDataAsset
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Instructions")
	TSoftObjectPtr<UWorld> TemplateMap;
#endif

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="Instructions")
	TArray<FFortBuildingInstruction> Instructions;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="Instructions")
	FBoxSphereBounds Bounds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="Instructions")
	TMap<int32, int32> BuildingAttachmentsInstructionsIndexesMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	int32 NumOfPiecesToSpawnAtOnce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	float TimeBetweenSpawns;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bSetOwnerID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bUsePlayerBuildAnimations;

private:
	UPROPERTY(EditAnywhere, Instanced, Category="Instructions")
	TArray<TObjectPtr<UFortBuildingInstructionModifier>> Modifiers;

	UPROPERTY(SaveGame)
	FString MapName;

};

