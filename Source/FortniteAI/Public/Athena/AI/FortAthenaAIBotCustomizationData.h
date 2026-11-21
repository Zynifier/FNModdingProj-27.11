// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/Datatables/MMRSpawningBracketTable.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "FortAthenaAIBotCustomizationData.generated.h"

class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class UBehaviorTree;
class UDataTable;
class UFortAthenaAIBotCharacterCustomization;
class UFortAthenaAIBotCosmeticLibraryData;
class UFortAthenaAIBotInventoryItems;
class UFortAthenaAIBotSkillSet;
class UFortAthenaAILODSettingsContainer;
class UFortBotNameSettings;

UENUM()
enum class BotDataOverrideCosmeticMode : uint8
{
	SpecificLoadout = 0,
	CosmeticLibrary = 1,
};

USTRUCT(BlueprintType)
struct FFortAthenaAIBotRunTimeCustomizationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visual")
	FGameplayTag PredefinedCosmeticSetTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Replication")
	float CullDistanceSquared;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn")
	bool bCheckForOverlaps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
	bool bHasCustomSquadId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
	uint8 CustomSquadId;

};

USTRUCT()
struct FMMRSpawningBracketNPCDataTableRow : public FMMRSpawningBracketBaseDataTableRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Tables Info")
	float Skill;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAIBotCustomizationData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Visual")
	void SetCharacterCustomizationFromPlayerPawn(const AFortPlayerPawn* InFortPawn);

private:
	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<AFortPlayerPawnAthena> PawnClass;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	uint8 bRequiresUniqueNetId : 1;

	UPROPERTY(EditDefaultsOnly, Category="Squad", meta=(AllowPrivateAccess="true"))
	uint8 bHasCustomSquadId : 1;

	UPROPERTY(EditDefaultsOnly, Category="Squad", meta=(AllowPrivateAccess="true", EditCondition="bHasCustomSquadId"))
	uint8 CustomSquadId;

	UPROPERTY(EditDefaultsOnly, Category="Death", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideCanRespawnOnDeath : 1;

	UPROPERTY(EditDefaultsOnly, Category="Death", meta=(AllowPrivateAccess="true", EditCondition="bOverrideCanRespawnOnDeath"))
	uint8 bCanRespawnOnDeath : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideBehaviorTree : 1;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideCharacterCustomization : 1;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideDBNOPlayStyle : 1;

	UPROPERTY(EditDefaultsOnly, Category="Skills", meta=(AllowPrivateAccess="true", EditCondition="!bUseMatchMMRToOverrideSkillLevel"))
	uint8 bOverrideSkillLevel : 1;

	UPROPERTY(EditDefaultsOnly, Category="Skills", meta=(AllowPrivateAccess="true", EditCondition="!bOverrideSkillLevel"))
	uint8 bUseMatchMMRToOverrideSkillLevel : 1;

	UPROPERTY(EditDefaultsOnly, Category="Skills", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideSkillSets : 1;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideStartupInventory : 1;

	UPROPERTY(EditDefaultsOnly, Category="Name", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideBotNameSettings : 1;

	UPROPERTY(EditDefaultsOnly, Category="Analytics", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideBotIDAnalyticsSuffix : 1;

	UPROPERTY(EditDefaultsOnly, Category="Construction", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideConstructionBuildingInfo : 1;

	UPROPERTY(EditDefaultsOnly, Category="Skills", meta=(AllowPrivateAccess="true", AssetBundles="Server", DisplayAfter="bUseMatchMMRToOverrideSkillLevel", EditCondition="bUseMatchMMRToOverrideSkillLevel"))
	TSoftObjectPtr<UDataTable> OverrideSkillLevelMMRTable;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true", DisplayAfter="bOverrideBehaviorTree", EditCondition="bOverrideBehaviorTree"))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AllowPrivateAccess="true", EditCondition="bOverrideCharacterCustomization"))
	BotDataOverrideCosmeticMode OverrideCosmeticMode;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Visual", meta=(AllowPrivateAccess="true", EditCondition="bOverrideCharacterCustomization"))
	TObjectPtr<UFortAthenaAIBotCharacterCustomization> CharacterCustomization;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AllowPrivateAccess="true", AssetBundles="Server", EditCondition="bOverrideCharacterCustomization"))
	TSoftObjectPtr<UFortAthenaAIBotCosmeticLibraryData> CosmeticCustomizationLibrary;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true", DisplayAfter="bOverrideDBNOPlayStyle", EditCondition="bOverrideDBNOPlayStyle"))
	EDBNOPlayStyle DBNOPlayStyle;

	UPROPERTY(EditDefaultsOnly, Category="Skills", meta=(AllowPrivateAccess="true", DisplayAfter="bOverrideSkillLevel", EditCondition="bOverrideSkillLevel"))
	float SkillLevel;

	UPROPERTY(EditDefaultsOnly, Category="Skills", meta=(AllowPrivateAccess="true", DisplayAfter="bOverrideSkillSets", EditCondition="bOverrideSkillSets"))
	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> SkillSetOverrideClasses;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Inventory", meta=(AllowPrivateAccess="true", DisplayAfter="bOverrideStartupInventory", EditCondition="bOverrideStartupInventory"))
	TObjectPtr<UFortAthenaAIBotInventoryItems> StartupInventory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Name", meta=(AllowPrivateAccess="true", DisplayAfter="bOverrideBotNameSettings", EditCondition="bOverrideBotNameSettings"))
	TObjectPtr<UFortBotNameSettings> BotNameSettings;

	UPROPERTY(EditDefaultsOnly, Category="Analytics", meta=(AllowPrivateAccess="true", DisplayAfter="bOverrideBotIDAnalyticsSuffix", EditCondition="bOverrideBotIDAnalyticsSuffix"))
	FString BotAnalyticsSuffix;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	float SpawnTracePadding;

	UPROPERTY(EditDefaultsOnly, Category="Construction", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EConstructionBuildingType"))
	FConstructionBuildingInfo OverrideConstructionBuildingInfo[6];

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(AllowPrivateAccess="true", AssetBundles="Server"))
	TSubclassOf<UFortAthenaAILODSettingsContainer> AILODSettingsContainer;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAILODSettingsContainer> AILODSettingsContainerLoaded;

};

