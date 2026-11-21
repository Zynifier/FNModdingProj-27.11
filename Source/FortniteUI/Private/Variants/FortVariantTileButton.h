// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "FortVariantTileButton.generated.h"

class UAthenaCosmeticItemDefinition;
class UFortApplyVarianceToInterfaceMaterialFlow;
class UImage;
class UMaterialInstance;
class UOverlay;
class UTexture2D;
class UVariantObject;

UCLASS(BlueprintType, Blueprintable)
class UFortVariantTileButton : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetEquippedState(bool bIsEquiped);

private:
	UPROPERTY(EditAnywhere, Category="Display Data")
	FLinearColor LockedTintColor;

	UPROPERTY(EditAnywhere, Category="Display Data")
	FName IconParamName;

	UPROPERTY(EditAnywhere, Category="Display Data")
	TSoftObjectPtr<UMaterialInstance> VariantMateral;

	UPROPERTY(EditDefaultsOnly, Category="Display Data")
	TSoftObjectPtr<UTexture2D> ExplicitlyNoneIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantTileButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_VariantDisplay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Locked;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantTileButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Conflict;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Active;

	UPROPERTY(Transient)
	TObjectPtr<UVariantObject> AssociatedVariant;

	UPROPERTY(Transient)
	TObjectPtr<UFortApplyVarianceToInterfaceMaterialFlow> MaterialVarianceFlowUI;

};

UCLASS()
class UVariantObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag VariantChannel;

	UPROPERTY()
	FGameplayTag VariantTag;

	UPROPERTY()
	FString VariantCustomData;

	UPROPERTY()
	bool bOwned;

	UPROPERTY()
	TObjectPtr<UAthenaCosmeticItemDefinition> CosmeticDef;

};

