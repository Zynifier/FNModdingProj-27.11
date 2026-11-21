// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "FortPlayerBanner.generated.h"

class UMaterialInterface;

UCLASS()
class UFortPlayerBanner : public UWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortPlayerBanner")
	bool bShowBorder;

	UPROPERTY(EditAnywhere, Category="FortPlayerBanner")
	bool bUseLargeTexture;

	UPROPERTY(EditAnywhere, Category="FortPlayerBanner")
	bool bSquareShape;

	UPROPERTY(EditAnywhere, Category="FortPlayerBanner")
	FVector2D DesiredSize;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> DefaultBorderlessBannerMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> DefaultBorderlessSquareBannerMaterial;

	UPROPERTY(Transient)
	FSlateBrush BannerBrush;

};

