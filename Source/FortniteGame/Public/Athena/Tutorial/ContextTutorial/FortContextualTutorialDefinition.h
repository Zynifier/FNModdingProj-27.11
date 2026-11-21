// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "FortContextualTutorialDefinition.generated.h"

class UFortContextualTutorial;
class UMediaSource;

UENUM()
enum class EFortContextualTutorialPlatform : uint8
{
	Any = 0,
	PcAndConsole = 1,
	Mobile = 2,
};

USTRUCT(BlueprintType)
struct FDirectiveInput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DirectiveInput")
	ECommonInputType Input;

	UPROPERTY(EditAnywhere, Category="DirectiveInput", meta=(MultiLine="TRUE"))
	FText Text;

	UPROPERTY(EditAnywhere, Category="DirectiveInput")
	TArray<FText> ABTestingTexts;

};

USTRUCT(BlueprintType)
struct FHUDElementToHighlight
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDElementToHighlight")
	FGameplayTagContainer HUDElementToHighlight;

	UPROPERTY(EditAnywhere, Category="HUDElementToHighlight")
	FGameplayTagContainer HUDSubElementToHighlight;

	UPROPERTY(EditAnywhere, Category="HUDElementToHighlight")
	FGameplayTagContainer UniqueHUDElementToHighlight;

};

UCLASS(Config=Game, MinimalAPI)
class UFortContextualTutorialDefinition : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	TSubclassOf<UFortContextualTutorial> ContextualTutorialClass;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	FGameplayTag TutorialType;

	UPROPERTY(EditAnywhere, Category="FortContextualTutorialDefinition")
	TObjectPtr<UMediaSource> MainMediaSource;

	UPROPERTY(EditAnywhere, Category="FortContextualTutorialDefinition")
	TObjectPtr<UMediaSource> SuccessMediaSource;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	int32 Priority;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="1", UIMin="1"))
	int32 AmountOfRecallMatches;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(MultiLine="TRUE"))
	TArray<FDirectiveInput> DirectiveMessages;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(MultiLine="TRUE"))
	FText InformativeMessage;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0.0", UIMin="0.0"))
	float TriggerActivationDelay;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0.0", UIMin="0.0"))
	float MessageDisplayTime;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0.0", UIMin="0.0"))
	float SuccesMessageDisplayTime;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0.0", UIMin="0.0"))
	float ReminderDelay;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0", UIMin="0"))
	int32 ReminderAmount;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0.0", UIMin="0.0"))
	float InformativeMessageDelay;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0.0", UIMin="0.0"))
	float LockedDelay;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0.0", EditCondition="bQueueActivation", UIMin="0.0"))
	float QueuedActivateDelay;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(InlineEditConditionToggle="QueuedActivateDelay"))
	bool bQueueActivation;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition", meta=(ClampMin="0", UIMin="0"))
	int32 AccountLevelLimit;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bCanBeShownInCombat;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bIsCompletionSilent;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bAlwaysSendSuccess;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bCanSetMessagingSystemOnCooldown;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bCanBeShownWhileDBNO;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	EFortContextualTutorialPlatform Platform;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	FGameplayTag ContextualTutorialDependency;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	FGameplayTagContainer AdditionalTutorialsToComplete;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	TArray<FHUDElementToHighlight> HudElementsToHighlight;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bRequireSquad;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bRequireSolo;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bActivateInBR;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bActivateInCreative;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	bool bIsEnabled;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition")
	TArray<EAthenaGamePhase> ExcludedGamePhases;

};

