// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Misc/Guid.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "Quests/QuestItemComponents/FortQuestItemComponent.h"
#include "Quests/QuestItemComponents/ObjectiveGateComponentTypes.h"
#include "FortQuestItemComponent_ObjectiveGate.generated.h"

class IQuestInstanceInterface;
class IQuestInstanceParticipantInterface;
class UFortGameplayAbility_ObjectiveGate;

USTRUCT()
struct FObjectiveEntry_Gate
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="-1"))
	EGateType GateType;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="0"))
	FName GateName;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="1"))
	uint8 bShouldGateStartOpen : 1;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="2", InlineEditConditionToggle))
	uint8 bUseAutomaticCloseTime : 1;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="4", InlineEditConditionToggle))
	uint8 bUseAutomaticOpenTime : 1;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="7", EditCondition="GateType == EGateType::Verb", EditConditionHides))
	uint8 bUseOpenVerbFilter : 1;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="9", EditCondition="GateType == EGateType::Verb", EditConditionHides))
	uint8 bUseCloseVerbFilter : 1;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="8", EditCondition="GateType == EGateType::SingleEvent", EditConditionHides))
	uint8 bUseOpenFilter : 1;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="11", EditCondition="GateType == EGateType::SingleEvent", EditConditionHides))
	uint8 bUseCloseFilter : 1;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="100"))
	uint8 bUseAdvancedLogic : 1;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="3", EditCondition="bUseAutomaticCloseTime", UIMin="0.1"))
	float TimeToCloseGateAfterOpen;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="5", EditCondition="bUseAutomaticOpenTime", UIMin="0.1"))
	float TimeToOpenGateAfterClose;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="6"))
	EGateResetBehavior GateResetBehavior;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(BaseStruct="/Script/FortniteGame.ObjectiveFilter", DisplayPriority="8", EditCondition="GateType == EGateType::Verb && bUseOpenVerbFilter", EditConditionHides, ExcludeBaseStruct))
	TArray<FInstancedStruct> OpenVerbFilters;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(BaseStruct="/Script/FortniteGame.ObjectiveFilter", DisplayPriority="10", EditCondition="GateType == EGateType::Verb && bUseCloseVerbFilter", EditConditionHides, ExcludeBaseStruct))
	TArray<FInstancedStruct> CloseVerbFilters;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="7", EditCondition="GateType == EGateType::SingleEvent", EditConditionHides))
	FGameplayTag OpenEventTag;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="9", EditCondition="bUseOpenFilter", EditConditionHides))
	FEventPayloadFilter OpenEventFilter;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="10", EditCondition="GateType == EGateType::SingleEvent", EditConditionHides))
	FGameplayTag CloseEventTag;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="12", EditCondition="bUseCloseFilter", EditConditionHides))
	FEventPayloadFilter CloseEventFilter;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="7", EditCondition="GateType == EGateType::GameplayAbility", EditConditionHides, MetaClass="/Script/FortniteGame.FortGameplayAbility_ObjectiveGate"))
	TSoftClassPtr<UFortGameplayAbility_ObjectiveGate> GateGameplayAbility;

	UPROPERTY(EditAnywhere, Category="ObjectiveEntry_Gate", meta=(DisplayPriority="101", EditCondition="bUseAdvancedLogic", EditConditionHides))
	TMap<FName, EObjectiveGateRelation> AdvancedGateLogic;

	UPROPERTY()
	FGameplayAbilitySpecHandle SpecHandle;

};

USTRUCT()
struct FMutableObjectiveExtension_Gate
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FObjectiveEntry_Gate> ObjectiveGates;

	UPROPERTY(Transient)
	EGateCheckType GateCheckType;

};

UCLASS()
class UFortQuestItemComponent_ObjectiveGate : public UFortQuestItemComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleRegisterGatesForAdditionalParticipant(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants);

	UFUNCTION()
	void HandleRemoveGatesFromAdditionalParticipant(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants);

	UFUNCTION()
	void SetGateOpenState(const FName ObjBackendName, const TSubclassOf<UFortGameplayAbility_ObjectiveGate> GateClass, const bool bInOpenCloseState);

	UFUNCTION()
	void SetVerbBasedGateOpenState(const FName ObjBackendName, const FGuid& GateID, const bool bInOpenCloseState);

private:
	UPROPERTY(Transient)
	TMap<FName, FMutableObjectiveExtension_Gate> ObjectivesExtensionDataMutable;

};

