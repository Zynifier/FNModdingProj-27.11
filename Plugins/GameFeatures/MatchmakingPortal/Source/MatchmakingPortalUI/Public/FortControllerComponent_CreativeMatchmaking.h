// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_CreativeMatchmaking.generated.h"

class UFortActivityDetailsModal;
class UFortCreativeMatchmakingFeedback;
class UFortGameActivity;
enum class EInGameReadyCheckStatus : uint8;

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_CreativeMatchmaking : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnCreativeReadyCheckStatusChanged(EInGameReadyCheckStatus InGameReadyCheckStatus);

	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> CachedGameActivity;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_CreativeMatchmaking")
	TSubclassOf<UFortCreativeMatchmakingFeedback> CreativeMatchmakingFeedbackClass;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_CreativeMatchmaking")
	TSubclassOf<UFortActivityDetailsModal> IslandModal;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortControllerComponent_CreativeMatchmaking", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeMatchmakingFeedback> CreativeMatchmakingFeedbackWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivityDetailsModal> MatchmakingPortalModalWidget;

};

