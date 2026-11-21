// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemTiles/FortItemTileButton.h"
#include "FortRotatingItemTileButton.generated.h"

class UFortItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortRotatingItemTileButton : public UFortItemTileButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CardPack")
	void RotateToNextItem();

	UFUNCTION(BlueprintCallable, Category="CardPack")
	void SetNeedsItemRotateAnimation(bool InNeedsItemRotationAnimation);

	UFUNCTION(BlueprintCallable, Category="CardPack")
	void SetTimeBeweenRotations(float InTimeBetweenRotations);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Tile")
	void StartPlayingRotateItemAnimation();

	UFUNCTION(BlueprintCallable, Category="CardPack")
	void StartRotating();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Tile")
	void StopPlayingRotateItemAnimation();

	UFUNCTION(BlueprintCallable, Category="CardPack")
	void StopRotating();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Tile")
	float TimeBetweenRotations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Tile")
	bool bNeedsItemRotateAnimation;

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> ItemsToRotate;

};

