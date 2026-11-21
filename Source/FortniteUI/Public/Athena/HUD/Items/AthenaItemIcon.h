// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Athena/HUD/Items/AthenaItemElementWidgetBase.h"
#include "AthenaItemIcon.generated.h"

class UAthenaItemTierWidget;
class UCommonTextBlock;
class UImage;
class UTexture2D;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaItemIcon : public UAthenaItemElementWidgetBase, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAmmoIconUpdated(const bool bHasAmmoIcon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemIconUpdated(const bool bHasItemIcon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStackCountTextUpdated(const bool bIsInfinite);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemIcon", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ItemIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemIcon", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StackCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemIcon", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_AmmoIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemIcon", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaItemTierWidget> ItemTierWidget;

	UPROPERTY(EditAnywhere, Category="AthenaItemIcon")
	bool bUseLargePreviewImage;

	UPROPERTY(EditAnywhere, Category="AthenaItemIcon")
	FName ItemIconTextureParamName;

	UPROPERTY(EditAnywhere, Category="AthenaItemIcon")
	FName AmmoIconTextureParamName;

	UPROPERTY(EditAnywhere, Category="AthenaItemIcon")
	bool bDisplayInitialAmmoCount;

	UPROPERTY(EditAnywhere, Category="AthenaItemIcon")
	bool bForceHideItemCount;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Update Item Icon", EditCondition="!bDesignTime_SetItemToRepresent"))
	bool bDesignTime_UpdateItemIcon;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Item Icon", EditCondition="bDesignTime_UpdateItemIcon"))
	TObjectPtr<UTexture2D> DesignTime_ItemIcon;
#endif

};

