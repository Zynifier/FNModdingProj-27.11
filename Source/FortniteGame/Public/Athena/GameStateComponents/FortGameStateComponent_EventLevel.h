// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/GameStateComponents/FortGameStateComponent_DynamicStreamingLevel.h"
#include "FortGameStateComponent_EventLevel.generated.h"

class AActor;
class AFortEventLevelCamera;
class AFortEventLevelNavigationActor;
class AFortPlayerController;
class ALevelSequenceActor;
class UAthenaRewardEventGraph;
class UCameraComponent;
class UFortCinematicCamera;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndRestedXpDrip);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveCameraChanged, FGameplayTag, CameraTag);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomOwnerChanged, AFortPlayerController*, OwningPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSpecialNavActorInteraction, FGameplayTag, InteractionTag, FGameplayTag, CameraTag, AFortEventLevelNavigationActor*, InActor);

USTRUCT()
struct FAnalyticsNavActorClickedData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AnalyticsNavActorClickedData")
	FGameplayTag InteractionCamera;

	UPROPERTY(EditAnywhere, Category="AnalyticsNavActorClickedData")
	FGameplayTagContainer InteractionActor;

	UPROPERTY(EditAnywhere, Category="AnalyticsNavActorClickedData")
	FName HumanReadable;

};

USTRUCT(BlueprintType)
struct FHiddenActors
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayTag RewardEventGraphNode;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> HiddenActors;

};

USTRUCT(BlueprintType)
struct FNavIndicatorTextList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="NavIndicatorTextList")
	FGameplayTag ListName;

	UPROPERTY(EditDefaultsOnly, Category="NavIndicatorTextList")
	TArray<FText> IndicatorTextList;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_EventLevel : public UFortGameStateComponent_DynamicStreamingLevel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	void CanGainRestedXp(bool& bResult) const;

	UFUNCTION(BlueprintCallable)
	void EndRestXpTimer();

	UFUNCTION(BlueprintPure)
	FGameplayTag GetActiveCameraTag() const;

	UFUNCTION(BlueprintPure)
	AFortEventLevelNavigationActor* GetLastNavObject() const;

	UFUNCTION(BlueprintCallable)
	FText GetRandomNavIndicatorTextFromList(const FGameplayTag& ListNameTag);

	UFUNCTION(BlueprintPure)
	AFortPlayerController* GetRoomOwner() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleObjectSpecialInteraction(FGameplayTag ActionTag, FGameplayTag CameraTag, AFortEventLevelNavigationActor* InActor);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void HandlePreOpenPackageComplete() const;

	UFUNCTION(BlueprintCallable)
	void HoverActorUnderCursor();

	UFUNCTION(BlueprintCallable)
	void LinkNavActorToCamera(AFortEventLevelNavigationActor* InActor, FGameplayTag CameraTag);

	UFUNCTION(BlueprintCallable)
	void NotifyRestedXpGenAmount(int32 RestedXp);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavActorHovered();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavActorSelected();

	UFUNCTION(BlueprintCallable)
	bool RegisterCamera(AFortEventLevelCamera* InCamera);

	UFUNCTION(BlueprintCallable)
	void RegisterHiddenActor(AActor* InActor, FGameplayTag EventGraphNode);

	UFUNCTION(BlueprintCallable)
	bool RegisterNavigationActor(AFortEventLevelNavigationActor* InActor);

	UFUNCTION(BlueprintCallable)
	void SetActiveCamera(FGameplayTag NewActiveCamera, bool bUseTransition = false);

	UFUNCTION(BlueprintCallable)
	void StartRestedXpTimer();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void TryToClaimRewardGraphNode(FGameplayTag NodeTag) const;

protected:
	UPROPERTY(BlueprintAssignable)
	FSpecialNavActorInteraction OnSpecialInterationTriggered;

	UPROPERTY(BlueprintAssignable)
	FEndRestedXpDrip OnRestedXpDripStopped;

	UPROPERTY(BlueprintAssignable)
	FOnRoomOwnerChanged RoomOwnerChanged;

	UPROPERTY(BlueprintAssignable)
	FOnActiveCameraChanged ActiveCameraChanged;

private:
	UFUNCTION(BlueprintCallable)
	void GoToCamera(FGameplayTag CameraToViewFrom);

	UFUNCTION(BlueprintCallable)
	void HandleNavigationActorUnhover(AFortEventLevelNavigationActor* InActor);

	UFUNCTION()
	void HandleOnCameraBlendComplete();

	UFUNCTION()
	void HandleOnCameraCut(UCameraComponent* CameraComponent);

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_EventLevel")
	TMap<FGameplayTag, bool> BangStateTracker;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortEventLevelCamera>> SceneCameras;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> RoomOwner;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_EventLevel")
	TSoftObjectPtr<UAthenaRewardEventGraph> AssignedRewardGraph;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaRewardEventGraph> RewardGraph;

	UPROPERTY(Transient)
	FGameplayTagContainer RewardGraphNodesVisuallyDisplayed;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortEventLevelNavigationActor>> ClickableActors;

	UPROPERTY(Transient)
	TArray<FHiddenActors> HiddenActorsToShowOnceClaimed;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortEventLevelNavigationActor> CurrentSelectedNavObj;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortEventLevelNavigationActor> CurrentHoveredNavObj;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_EventLevel")
	TSubclassOf<UFortCinematicCamera> EventLevelCinematicOverrideClass;

	UPROPERTY(Transient)
	FGameplayTag ActiveCamera;

	UPROPERTY(Transient)
	FGameplayTag CameraToTurnLightSwitchOff;

	UPROPERTY(Transient)
	TSoftObjectPtr<ALevelSequenceActor> TransitionSequencer;

	UPROPERTY(Transient)
	FGameplayTag SelectedCamera;

	UPROPERTY(Transient)
	FGameplayTag LastSelectedNavObj;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortEventLevelCamera>> CamerasPendingRegistration;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortEventLevelNavigationActor>> NavigationActorsPendingRegistration;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_EventLevel")
	TArray<FAnalyticsNavActorClickedData> NavigationActorClickedData;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	FScalableFloat AnalogInputModifier;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_EventLevel")
	TArray<FNavIndicatorTextList> NavIndicatorTextLists;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_EventLevel")
	bool bAllowNavigationToHiddenActors;

};

