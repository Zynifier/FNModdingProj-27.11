// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortRichTextTextureDecorator.generated.h"

class UMaterialInterface;
class UObject;
class UTexture2D;

UCLASS()
class UFortRichTextTextureDecorator : public URichTextBlockDecorator
{
	GENERATED_BODY()

public:
	UFortRichTextTextureDecorator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(Transient)
	TObjectPtr<UObject> LoadedResourceObject;

};

UCLASS()
class UFortRichTextTextureDecoratorHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortRichText")
	static FText MakeFortRichTextMaterial(const TSoftObjectPtr<UMaterialInterface> InMaterial, const bool bUseDesiredSize = true, const int32 Width = 20, const int32 Height = 20);

	UFUNCTION(BlueprintPure, Category="FortRichText")
	static FText MakeFortRichTextTexture(const TSoftObjectPtr<UTexture2D> InTexture, const bool bUseDesiredSize = true, const int32 Width = 20, const int32 Height = 20);

};

