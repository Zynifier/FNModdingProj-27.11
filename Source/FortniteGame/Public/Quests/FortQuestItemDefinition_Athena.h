// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/FortQuestItemDefinition.h"
#include "Quests/FortQuestItemDefinition_AthenaEnums.h"
#include "Quests/LockedQuestData.h"
#include "FortQuestItemDefinition_Athena.generated.h"

class UFortQuestItemDefinition;
class UFortSoundSequence;
class UFortTandemCharacterData;
class UObject;
enum class EFortQuestSubtype : uint8;

UCLASS(MinimalAPI, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "FortItemDefinition"))
class UFortQuestItemDefinition_Athena : public UFortQuestItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	EFortQuestSubtype GetQuestSubtype() const;

	UFUNCTION(Category="QuestItemDefinition")
	TSoftObjectPtr<UFortTandemCharacterData> GetSoftTandemCharacterData() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	UFortTandemCharacterData* GetTandemCharacterData() const;

protected:
	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition_Athena")
	EFortQuestSubtype QuestSubtype;

	UPROPERTY()
	bool bForceExpiryExport;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestItemDefinition_Athena")
	int32 Threshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestItemDefinition_Athena")
	int32 InitialProgress;

	UPROPERTY(EditAnywhere, Category="QuestRewards")
	TArray<FString> FulfillmentRewards;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition_Athena")
	TObjectPtr<UFortSoundSequence> IntroSoundSequence;

private:
	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition_Athena")
	uint8 bIsShared : 1;

	UPROPERTY(EditAnywhere, Category="Transient")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> TransientPrerequisiteQuests;

	UPROPERTY(EditAnywhere, Category="Transient")
	bool bGrantTransientQuestToSquad;

	UPROPERTY(EditAnywhere, Category="Transient")
	bool bShowIfGrantedEarly;

	UPROPERTY(EditAnywhere, Category="Transient")
	bool bTransientAutoComplete;

	UPROPERTY(EditAnywhere, Category="Transient")
	bool bAllowMultipleCompletionsPerMatch;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestItemDefinition_Athena")
	int32 ExpirationDuration;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition_Athena", meta=(AssetBundles="MenuAthena,ZoneAthena"))
	TSoftObjectPtr<UFortTandemCharacterData> TandemCharacterData;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestItemDefinition_Athena")
	FString CalendarEventTag;

	UPROPERTY(EditAnywhere, Category="Display", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> NotificationIconOverride;

	UPROPERTY(EditAnywhere, Category="Display", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> QuestGiverWidgetIcon;

	UPROPERTY(EditAnywhere, Category="Locked Quests")
	FLockedQuestConfigData LockedQuestConfigData;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FortQuestItemDefinition_Athena")
	FString AthenaLevelUpIdentifier;
#endif

};

