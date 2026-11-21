// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_DrawTaggedPlayerIndicators.generated.h"

class AFortGameStateAthena;
class UFortPlaylist;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FDrawTaggedPlayerIndicatorsData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FGameplayTag PlayerTag;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FSlateBrush LocalPlayerBrush;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FSlateBrush FriendBrush;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FSlateBrush EnemyBrush;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FScalableFloat bHotfixRenderLocalPlayer;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FScalableFloat bHotfixRenderEnemy;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FScalableFloat HotfixEnemyRenderDistance2D;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FScalableFloat bHotfixRenderFriend;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DrawTaggedPlayerIndicatorsData")
	FScalableFloat HotfixFriendRenderDistance2D;

	UPROPERTY(Transient)
	float EnemyRenderDistance2D;

	UPROPERTY(Transient)
	float FriendRenderDistance2D;

	UPROPERTY(Transient)
	bool bRenderLocalPlayer;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_DrawTaggedPlayerIndicators : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Replicated, Category="FortAthenaMutator_DrawTaggedPlayerIndicators")
	TArray<FDrawTaggedPlayerIndicatorsData> DrawingDataArray;

private:
	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

};

