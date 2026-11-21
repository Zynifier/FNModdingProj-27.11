// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonLazyImage.h"
#include "Math/Color.h"
#include "FortBrushSize.h"
#include "FortLazyImage.generated.h"

class UFortItem;
class UFortItemDefinition;
class UMaterialInterface;
class UObject;
class UTexture2D;

UCLASS(meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortLazyImage : public UCommonLazyImage
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void SetBrushFromItemDefinition(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable)
	void SetBrushFromItemInstance(const UFortItem* ItemInstance);

	UFUNCTION(BlueprintCallable)
	void SetBrushFromURL(const FString& CMSImageURL, bool bMatchSize = false);

	UFUNCTION(BlueprintCallable)
	void SetFortBrushSize(EFortBrushSize::Type FortBrushSize);

	UFUNCTION(BlueprintCallable)
	void SetFromLazyMaterialAndTexture(const TSoftObjectPtr<UMaterialInterface>& LazyMaterial, const TSoftObjectPtr<UTexture2D>& LazyTexture, const FName& ParameterName);

	UFUNCTION(BlueprintCallable)
	void SetShadowColorAndOpacity(FLinearColor InColorAndOpacity);

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="DesignerPreview")
	TObjectPtr<UFortItemDefinition> DesignerPreviewItem;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="DesignerPreview")
	bool bIsImageForDesignerPreviewOnly;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UObject> DesignerPreviewResourceObject;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Appearance", meta=(AllowPrivateAccess="TRUE", ExposeOnSpawn="TRUE"))
	bool bApplyDropShadow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Appearance", meta=(AllowPrivateAccess="TRUE", EditCondition="bApplyDropShadow", ExposeOnSpawn="TRUE", sRGB="true"))
	FLinearColor ShadowColorAndOpacity;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDefinition_DEPRECATED;
#endif

};

