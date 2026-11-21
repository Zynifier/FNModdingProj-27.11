// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Frontend/ItemPreview/ItemPreviewRotator.h"
#include "TurntableItemPreviewRotator.generated.h"

class UAthenaCosmeticItemDefinition;
class USceneComponent;
enum class EFrontEndCamera : uint8;

UCLASS(BlueprintType, Blueprintable)
class ATurntableItemPreviewRotator : public AItemPreviewRotator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	USceneComponent* GetRotatingComponent() const;

	UFUNCTION(BlueprintPure)
	const FRotator& GetTurntablePedestalRotationOffset() const;

	UFUNCTION(BlueprintCallable)
	void InitializePreview(EFrontEndCamera Camera);

	UFUNCTION(BlueprintCallable)
	void RestoreTurntableZoomLevel();

	UFUNCTION(BlueprintCallable)
	void SetTurntablePedestalRotationOffset(const FRotator& InRotationOffset, bool bSnap = true);

	UFUNCTION(BlueprintCallable)
	void SetTurntableZoomLevel(float InZoomLevel, bool bSnap = true);

	UFUNCTION(BlueprintCallable)
	void ViewCosmeticDeveloperItemOverride();

	UFUNCTION(BlueprintCallable)
	void ViewCosmeticDeveloperLoadout();

private:
	UFUNCTION(BlueprintCallable)
	void LoadItemDefinition(UAthenaCosmeticItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable)
	void LoadLoadout(FFortAthenaLoadout Loadout);

};

