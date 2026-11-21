// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "FortVariantItemButtonMP.generated.h"

class UFortApplyVarianceToInterfaceMaterialFlow;
class UFortVariantItemVM;
class UImage;
class UMaterialInstance;
class UTexture2D;

UCLASS(BlueprintType, Blueprintable)
class UFortVariantItemButtonMP : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UFortVariantItemVM* GetAssociatedVariant();

	UFUNCTION(BlueprintCallable)
	void SetupVariantPreviewImage();

private:
	UPROPERTY(EditAnywhere, Category="Display Data")
	FLinearColor LockedTintColor;

	UPROPERTY(EditAnywhere, Category="Display Data")
	FName IconParamName;

	UPROPERTY(EditAnywhere, Category="Display Data")
	TSoftObjectPtr<UMaterialInstance> VariantMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Display Data")
	TSoftObjectPtr<UTexture2D> ExplicitlyNoneIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantItemButtonMP", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_VariantDisplay;

	UPROPERTY(Transient)
	TObjectPtr<UFortApplyVarianceToInterfaceMaterialFlow> MaterialVarianceFlowUI;

};

