// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortQuestObjectiveInfo.generated.h"

class AFortPlayerState;
class UFortConversation;
class UFortQuestItem;
class UTexture2D;

USTRUCT(BlueprintType)
struct FFortObjectiveAvailableConversation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<UFortConversation> ConversationRef;

	UPROPERTY()
	uint8 PlaysRemaining;

};

USTRUCT(BlueprintType)
struct FFortObjectiveAvailableConversationTriggerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint16 StatTarget;

	UPROPERTY()
	uint16 CurrentCounter;

	UPROPERTY()
	bool bCounterWraps;

	UPROPERTY(EditAnywhere, Category="FortObjectiveAvailableConversationTriggerInfo")
	TArray<FFortObjectiveAvailableConversation> ConversationList;

};

USTRUCT(BlueprintType)
struct FFortQuestObjectiveDisplayInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	int32 DisplayStage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	int32 DisplayMaxStage;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortQuestObjectiveInfo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Quest")
	FText GetObjectiveDescription() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	UFortQuestItem* GetOwningQuest() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasCompleted() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsActive() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsInProgress() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsVisibleToUser() const;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	FName BackendName;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	EFortQuestObjectiveStatEvent StatEvent;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	EFortQuestObjectiveItemEvent ItemEvent;

	UPROPERTY(BlueprintReadOnly, Category="HUD")
	TObjectPtr<UTexture2D> HudIcon;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	FFortQuestObjectiveDisplayInfo ObjectiveDisplayInfo;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	int32 AchievedCount;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	int32 RequiredCount;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	int32 LastNotifiedCount;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	int32 LastKnownMCPCount;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	TWeakObjectPtr<AFortPlayerState> QuestOwner;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveInfo")
	TWeakObjectPtr<AFortPlayerState> AssistPlayerState;

private:
	UFUNCTION()
	void DisplayDynamicQuestUpdate();

	UPROPERTY()
	uint8 bVisible : 1;

	UPROPERTY()
	uint8 bActive : 1;

	UPROPERTY()
	uint8 bAlreadyUpdatedThisMatch : 1;

	UPROPERTY()
	TArray<FFortObjectiveAvailableConversationTriggerInfo> AvailableConversationTriggers;

};

