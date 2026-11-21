// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortMarkableActorInterface.generated.h"

UENUM()
enum class EMarkableResult : uint8
{
	/** Allows markers to attach to this actor */
	Markable = 0,
	/** Stops the mark trace where it hit the actor, and position the ping at the point of impact. */
	Block = 1,
	/** Allows the mark trace to go through the actor as if it wasn't there */
	Continue = 2,
	/** Allows the marker to snap to this actor, but stay at that location without following the actor around */
	MarkableWithoutAttaching = 3,
};

UINTERFACE(MinimalAPI, BlueprintType, meta=(Category="MarkableActor"))
class UFortMarkableActorInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortMarkableActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="MarkableActor")
	FName GetMarkerDetailsId() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="MarkableActor")
	FGameplayTagContainer GetTargetTagsForQuestEvent() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="MarkableActor", meta=(DisplayName="SetCanBeMarked"))
	void SetCanBeMarked(const bool bInCanBeMarked);

};

