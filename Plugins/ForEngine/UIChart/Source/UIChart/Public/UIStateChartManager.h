// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UIStateChartContext.h"
#include "UIStateTransitionUrgency.h"
#include "UIStateChartManager.generated.h"

class ULocalPlayer;
class UUIStateChart;
class UUIStateChartContext;
class UUIStateChartManagerPlayer;
class UUIStateChartResourceCollection;
enum class EUIStateTransitionUrgency : uint8;

UCLASS()
class UICHART_API UUIStateChartManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UUIStateChartContext* GetContext() const;

protected:
	UFUNCTION(BlueprintCallable, Category="UI Chart", meta=(AutoCreateRefTerm="AnimationHints", DisplayName="AddStateChart"))
	int32 BP_AddStateChart(const UUIStateChart* StateChartAsset, ULocalPlayer* OwningLocalPlayer, const FGameplayTagContainer& AnimationHints, const FGameplayTag InitialStateTag, EUIStateTransitionUrgency Urgency = EUIStateTransitionUrgency::Normal);

	UFUNCTION(BlueprintCallable, Category="UI Chart", meta=(AutoCreateRefTerm="AnimationHints,ContextChanges", DisplayName="DeactivateStateChart"))
	bool BP_DeactivateStateChart(int32 Key, const FGameplayTagContainer& AnimationHints, const FUIStateChartContextChangeSet& ContextChanges, EUIStateTransitionUrgency Urgency = EUIStateTransitionUrgency::Normal);

	UFUNCTION(BlueprintCallable, Category="UI Chart", meta=(AutoCreateRefTerm="AnimationHints,ContextChanges", DisplayName="DispatchTransitionEvent"))
	bool BP_DispatchTransitionEvent(const FGameplayTag TransitionTag, const ULocalPlayer* StateChartOwner, const FGameplayTagContainer& AnimationHints, const FUIStateChartContextChangeSet& ContextChanges, EUIStateTransitionUrgency Urgency = EUIStateTransitionUrgency::Normal, bool bBacktrack = false);

	UFUNCTION(BlueprintCallable, Category="UI Chart", meta=(AutoCreateRefTerm="AnimationHints", DisplayName="ReactivateStateChart"))
	void BP_ReactivateStateChart(int32 Key, const FGameplayTagContainer& AnimationHints, const FGameplayTag StateTag, EUIStateTransitionUrgency Urgency = EUIStateTransitionUrgency::Normal);

	UFUNCTION(BlueprintCallable, Category="UI Chart", meta=(AutoCreateRefTerm="AnimationHints,ContextChanges", DisplayName="RemoveStateChart"))
	bool BP_RemoveStateChart(int32 Key, const FGameplayTagContainer& AnimationHints, const FUIStateChartContextChangeSet& ContextChanges, EUIStateTransitionUrgency Urgency = EUIStateTransitionUrgency::Normal);

	UPROPERTY()
	TMap<ULocalPlayer*, UUIStateChartManagerPlayer*> PlayerEntries;

	UPROPERTY(Transient)
	TArray<UUIStateChartManagerPlayer*> RemovedPlayerEntries;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartContext> Context;

	UPROPERTY(Instanced)
	TObjectPtr<UUIStateChartResourceCollection> GlobalResources;

};

