// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "UEKittTexture.generated.h"

UCLASS(HideCategories=("Adjustments", "Compositing", "LevelOfDetail", "ImportSettings", "Object"))
class UEKITTTEXTURE_API UUEKittTexture : public UTexture
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UEKitt Texture")
	FIntPoint Dimensions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UEKitt Texture")
	FLinearColor ClearColor;

};

