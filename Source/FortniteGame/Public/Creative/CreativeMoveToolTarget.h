// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeMoveToolTarget.generated.h"

class AActor;
class AFortCreativeMoveTool;

UINTERFACE(MinimalAPI, BlueprintType)
class UCreativeMoveToolTarget : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API ICreativeMoveToolTarget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	bool AllowInverseScaling();

	UFUNCTION(BlueprintImplementableEvent)
	bool ForceGridAlignment();

	UFUNCTION(BlueprintImplementableEvent)
	TArray<AActor*> GetAdditionalSelectableActors();

	UFUNCTION(BlueprintNativeEvent)
	float GetScaleMax(const float DefaultScaleMax);

	UFUNCTION(BlueprintNativeEvent)
	float GetScaleMin(const float DefaultScaleMin);

	UFUNCTION(BlueprintImplementableEvent)
	TArray<AActor*> GetSpawnedActors();

	UFUNCTION(BlueprintImplementableEvent)
	bool HasAdditionalSelectableActors();

	UFUNCTION(BlueprintImplementableEvent)
	bool HasAdditionalValidPlacementLogic() const;

	UFUNCTION(BlueprintImplementableEvent)
	bool IsValidPlacement();

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly)
	void OnCreativeToolDeletion();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnMoveToolScalingToggled(bool bScalingActive);

	UFUNCTION(BlueprintImplementableEvent)
	bool OnPreviewEnd();

	UFUNCTION(BlueprintImplementableEvent)
	bool OnPreviewStart();

	UFUNCTION(BlueprintImplementableEvent)
	bool ShouldBlockPlacement(const AFortCreativeMoveTool* MoveTool) const;

};

