// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Frontend/Spatial/SpatialScreen.h"
#include "SpatialItemPreviewScreen.generated.h"

class UAnimationAsset;
class UFortItemView;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialItemPreviewScreen : public UAthenaSpatialScreen
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Instanced)
	TObjectPtr<UFortItemView> ItemViewObject;

private:
	UPROPERTY(EditDefaultsOnly, Category="Mannequin")
	FName ItemPreviewActorTag;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialItemPreviewScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ItemPreviewRotateInputAction;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialItemPreviewScreen")
	bool bEnableItemPreviewRotation;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialItemPreviewScreen")
	TObjectPtr<UAnimationAsset> IdleAnimation;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialItemPreviewScreen")
	bool bLooping;

};

