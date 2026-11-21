// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture.h"
#include "Engine/TextureDefines.h"
#include "HarmonixAudioReactivity/Texture/HarmonixTextureFilterMode.h"
#include "HarmonixTextureBase.generated.h"

UCLASS(Abstract, HideCategories=("Object", "Texture", "Adjustments", "Compression", "LevelOfDetail", "Compositing", "ImportSettings"))
class HARMONIXAUDIOREACTIVITY_API UHarmonixTextureBase : public UTexture
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="HarmonixTextureBase")
	int32 GetCurrentTextureHeight() const;

	UFUNCTION(BlueprintPure, Category="HarmonixTextureBase")
	int32 GetCurrentTextureWidth() const;

protected:
	UPROPERTY(EditAnywhere, Category="HarmonixTextureBase", meta=(ClampMax="1024", ClampMin="2"))
	int32 Width;

private:
	UPROPERTY(EditAnywhere, Category="HarmonixTextureBase")
	EHarmonixTextureFilterMode TextureFilterMode;

	UPROPERTY(EditAnywhere, Category="HarmonixTextureBase")
	TEnumAsByte<TextureAddress> TextureTilingMode;

};

