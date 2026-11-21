// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortRichTextTextureDecorator.h"

UFortRichTextTextureDecorator::UFortRichTextTextureDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FText UFortRichTextTextureDecoratorHelpers::MakeFortRichTextMaterial(const TSoftObjectPtr<UMaterialInterface> InMaterial, const bool bUseDesiredSize, const int32 Width, const int32 Height)
{
	return FText();
}

FText UFortRichTextTextureDecoratorHelpers::MakeFortRichTextTexture(const TSoftObjectPtr<UTexture2D> InTexture, const bool bUseDesiredSize, const int32 Width, const int32 Height)
{
	return FText();
}
