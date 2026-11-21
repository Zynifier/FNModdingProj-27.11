// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralDataMap.h"
#include "ProceduralTextureColorChannel.h"
#include "ProceduralTextureMap.generated.h"

class UMaterialInterface;
class UTexture2D;
class UTextureRenderTarget2D;

USTRUCT(BlueprintType)
struct FProceduralTextureSource
{
	GENERATED_BODY()

public:
	/** Whether to use Texture of RenderTarget as source. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source", meta=(InlineEditConditionToggle))
	bool bUseRenderTarget;

	/** Texture to read from. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source", meta=(DisallowedAssetDataTags="VirtualTextureStreaming=True", EditCondition="!bUseRenderTarget"))
	TObjectPtr<UTexture2D> Texture;

	/** Render Target to read from. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source", meta=(EditCondition="bUseRenderTarget"))
	TObjectPtr<UTextureRenderTarget2D> RenderTarget;

	/** Render material to use on Render Target. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source", meta=(EditCondition="bUseRenderTarget"))
	TObjectPtr<UMaterialInterface> RenderTargetMaterial;

	/** Whether to tile the source or to stretch it to fit target area. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source")
	bool bStretchToFit;

	/** The size of one texel in cm. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source", meta=(ClampMin="1.0", EditCondition="!bStretchToFit", UIMin="1.0"))
	float TexelSize;

	/** X Offset factor to apply when sampling texture (Factor of texture dimension). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source", meta=(ClampMax="1.0", ClampMin="0.0", DisplayName="X Offset", EditCondition="!bStretchToFit", UIMax="1.0", UIMin="0.0"))
	float XOffset;

	/** Y Offset factor to apply when sampling texture (Factor of texture dimension). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source", meta=(ClampMax="1.0", ClampMin="0.0", DisplayName="Y Offset", EditCondition="!bStretchToFit", UIMax="1.0", UIMin="0.0"))
	float YOffset;

	/** Rotation to apply when sampling texture. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source", meta=(ClampMax="359", ClampMin="0", EditCondition="!bStretchToFit", UIMax="359", UIMin="0", Units="deg"))
	float Rotation;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object", "Object"), AutoExpandCategories=("Source", "DataMapping"))
class UProceduralTextureFloatMap : public UProceduralFloatDataMap
{
	GENERATED_BODY()

public:
	/** Channel to read from (used when using source as single channel). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source")
	EProceduralTextureColorChannel Channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source")
	FProceduralTextureSource Source;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object", "Object"), AutoExpandCategories=("Source", "DataMapping"))
class UProceduralTextureVectorMap : public UProceduralVectorDataMap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source")
	FProceduralTextureSource Source;

};

