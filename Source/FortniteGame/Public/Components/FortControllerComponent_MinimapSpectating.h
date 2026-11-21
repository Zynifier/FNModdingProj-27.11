// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Components/FortControllerComponent_Minimap.h"
#include "FortControllerComponent_MinimapSpectating.generated.h"

class AActor;
class UInputComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_MinimapSpectating : public UFortControllerComponent_Minimap
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void FullScreenMapCursorMoved(const FVector2D& CursorWidgetLocation, const FVector2D& CursorDelta);

	UFUNCTION(BlueprintCallable)
	void FullScreenMapCursorStartDrag();

	UFUNCTION(BlueprintCallable)
	void FullScreenMapCursorStopDrag();

	UFUNCTION(BlueprintCallable)
	void FullscreenMapZoom(float Value);

	UFUNCTION(BlueprintPure)
	bool GetMapWeaponTracersEnabled() const;

	UFUNCTION(BlueprintPure)
	bool GetShowBusPathsOnMap() const;

	UFUNCTION(BlueprintPure)
	bool GetShowPlayersOnMap() const;

	UFUNCTION(BlueprintPure)
	bool GetShowVehiclesOnMap() const;

	UFUNCTION(BlueprintCallable)
	void SetMapWeaponTracersEnabled(bool bEnable);

	UFUNCTION(BlueprintCallable)
	void SetShowBusPathsOnMap(bool bInShowBusPathsOnMap);

	UFUNCTION(BlueprintCallable)
	void SetShowPlayersOnMap(bool bInShowPlayersOnMap);

	UFUNCTION(BlueprintCallable)
	void SetShowVehiclesOnMap(bool bInShowVehiclesOnMap);

	UPROPERTY(BlueprintReadWrite, Category="FortControllerComponent_MinimapSpectating")
	float ZoomThresholdForPlayerNames;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AActor> HoveredActor;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> FullScreenMapInputComponent;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapPlayerIconColorBase;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapPlayerIconColorHovered;

};

