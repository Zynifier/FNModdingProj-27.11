// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Misc/Guid.h"
#include "FortTeamEnum.h"
#include "Items/FortPersistentTypes.h"
#include "Missions/FortMissionState.h"
#include "Missions/MissionTypes.h"
#include "FortObjectiveBase.generated.h"

class AFortMission;
class AFortObjectiveBase;
class UFortBadgeItemDefinition;
class UFortMissionTimerComponent;
class UFortWorldItemDefinition;
class UTexture2D;
enum class EFortMissionVisibilityOverride : uint8;
enum class EFortObjectiveStatus : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnObjectiveIsVisibilityOverrideChanged, const AFortObjectiveBase*, Objective, EFortMissionVisibilityOverride, NewVisibilityOverride);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnObjectiveIsVisibleChanged, const AFortObjectiveBase*, Objective, bool, bNewVisibility);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnObjectiveStatusChanged, const AFortObjectiveBase*, Objective, EFortObjectiveStatus, NewStatus);

UCLASS(NotPlaceable, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class AFortObjectiveBase : public AFortMissionState
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCosmetic, Category="Objective")
	int32 BlueprintGetNumProgressBars() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCosmetic, Category="Objective")
	FText BlueprintGetObjectiveDisplayText() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCosmetic, Category="Objective")
	FLinearColor BlueprintGetProgressBarColor(int32 ProgressBarIdx) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCosmetic, Category="Objective")
	UTexture2D* BlueprintGetProgressBarIcon(int32 ProgressBarIdx) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCosmetic, Category="Objective")
	float BlueprintGetProgressBarPercentage(int32 ProgressBarIdx) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCosmetic, Category="Objective")
	FText BlueprintGetProgressBarText(int32 ProgressBarIdx) const;

	UFUNCTION(BlueprintCallable, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void EnableTick(bool bEnabled);

	UFUNCTION(BlueprintPure, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	AFortMission* GetMission() const;

	UFUNCTION(BlueprintPure, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	FGuid GetMissionGuid() const;

	UFUNCTION(BlueprintPure, Category="Objective")
	virtual FText GetObjectiveDisplayString() const;

	UFUNCTION(BlueprintCallable, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	void GetRewardItemsByTag(const FGameplayTag RewardTag, TArray<UFortWorldItemDefinition*>& OutRewardItems);

	UFUNCTION(BlueprintPure, Category="Objective", meta=(UnsafeDuringActorConstruction="true"))
	UFortMissionTimerComponent* GetTimerComponent() const;

	UFUNCTION(BlueprintPure, Category="Team")
	bool IsRelevantToASpecificTeam() const;

	UFUNCTION(BlueprintPure, Category="Team")
	bool IsRelevantToTeam(uint8 Team) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions")
	void OnGenericObjectiveEvent();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(DeprecatedFunction, DeprecationMessage="Use SetUIVisibilityOverride instead.", UnsafeDuringActorConstruction="true"))
	void SetUiVisibility(bool bInIsObjectiveVisible);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(UnsafeDuringActorConstruction="true"))
	void SetUIVisibilityOverride(EFortMissionVisibilityOverride InVisibilityOverride);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(UnsafeDuringActorConstruction="true"))
	virtual bool StartPlayingObjective();

	UPROPERTY(SaveGame)
	TObjectPtr<UFortBadgeItemDefinition> ObjectiveRewardBadge;

	UPROPERTY(EditAnywhere, Category="Objective")
	TArray<TObjectPtr<UFortWorldItemDefinition>> ItemsToGiveOnObjectiveStart;

	UPROPERTY(EditAnywhere, Category="Objective")
	bool bStartPlayingOnMissionStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Objective")
	bool bAcceptsMissionEventsWhenFinished;

	UPROPERTY(BlueprintReadOnly, SaveGame, Replicated, Category="FortObjectiveBase")
	FGameplayTagContainer ObjectiveHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Analytics")
	FString ObjectiveAnalyticsName;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, SaveGame, Category="Objective")
	TEnumAsByte<EFortObjectiveRequirement::Type> MissionRequirement;

	UPROPERTY(BlueprintAssignable, Category="Mission")
	FOnObjectiveStatusChanged OnObjectiveStatusChanged;

	UPROPERTY(BlueprintAssignable, Category="Mission")
	FOnObjectiveIsVisibleChanged OnObjectiveVisibilityChanged;

	UPROPERTY(BlueprintAssignable, Category="Mission")
	FOnObjectiveIsVisibilityOverrideChanged OnObjectiveVisibilityOverrideChanged;

protected:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void AttemptMissionSave(const FString& OptionalSaveName);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Objective", meta=(DisplayName="OnObjectiveLoaded"))
	void BlueprintOnActivated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Objective")
	void BlueprintOnObjectiveEnd(EFortObjectiveStatus Status);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Objective", meta=(DisplayName="OnObjectiveStartPlaying"))
	void BlueprintOnStartPlaying();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions", meta=(DisplayName="PostObjectiveLoad"))
	void BlueprintPostObjectiveLoad();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void ClearObjectiveTimer();

	UFUNCTION(BlueprintPure, Category="Objective", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	float GetObjectiveTimerTimeRemaining() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void GrantRewardsByTag(const FGameplayTag RewardTag, EFortRewardType::Type RewardType);

	UFUNCTION(BlueprintPure, Category="Objective", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	bool IsObjectiveTimerPaused() const;

	UFUNCTION()
	void OnRep_bIsObjectiveVisible();

	UFUNCTION()
	void OnRep_ObjectiveStatus();

	UFUNCTION()
	void OnRep_ObjectiveVisibilityOverride();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void PauseObjectiveTimer();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void SetObjectiveTimer(const FString& FunctionName, float TimerLength, bool bStartPaused = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(UnsafeDuringActorConstruction="true"))
	virtual void StopObjective(EFortObjectiveStatus Status, const FString& Description, UFortBadgeItemDefinition* ExtraBadgeToGrant);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Objective", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void UnpauseObjectiveTimer();

	UPROPERTY(BlueprintReadOnly, SaveGame, ReplicatedUsing=OnRep_bIsObjectiveVisible, Category="Display")
	bool bIsObjectiveVisible;

	UPROPERTY(BlueprintReadOnly, SaveGame, ReplicatedUsing=OnRep_ObjectiveVisibilityOverride, Category="Display")
	EFortMissionVisibilityOverride VisibilityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Replicated, Category="Display")
	bool bIsProgressBarHidden;

	UPROPERTY(BlueprintReadOnly, SaveGame, Replicated, Category="Display")
	EFortMissionAudibility ObjectiveAudiblity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Team")
	bool bRelevantToSpecificTeam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Team", meta=(EditCondition="bRelevantToSpecificTeam"))
	TEnumAsByte<EFortTeam::Type> RelevantTeam;

	UPROPERTY(BlueprintReadOnly, SaveGame, ReplicatedUsing=OnRep_ObjectiveStatus, Category="Objective")
	EFortObjectiveStatus ObjectiveStatus;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortObjectiveBase", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UFortMissionTimerComponent> TimerComponent;

};

