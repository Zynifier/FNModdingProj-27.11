// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemComponentBase.h"
#include "ItemComponent_DisplayUI.generated.h"

class UMaterialInterface;
class UTexture2D;

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemComponent_DisplayUI : public UItemComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="UI Component")
	const FText& GetItemDescription() const;

	UFUNCTION(BlueprintPure, Category="UI Component")
	const TSoftObjectPtr<UTexture2D>& GetItemIcon() const;

	UFUNCTION(BlueprintPure, Category="UI Component")
	const TSoftObjectPtr<UMaterialInterface>& GetItemMaterial() const;

	UFUNCTION(BlueprintPure, Category="UI Component")
	const FText& GetItemName() const;

	UFUNCTION(BlueprintPure, Category="UI Component")
	const FName& GetMaterialTextureParameter() const;

	UFUNCTION(BlueprintPure, Category="UI Component")
	const TSoftObjectPtr<UTexture2D>& GetSmallItemIcon() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="UI Component")
	FText ItemName;

	UPROPERTY(EditDefaultsOnly, Category="UI Component")
	FText ItemDescription;

	UPROPERTY(EditDefaultsOnly, Category="UI Component")
	TSoftObjectPtr<UTexture2D> ItemIcon;

	UPROPERTY(EditDefaultsOnly, Category="UI Component")
	TSoftObjectPtr<UTexture2D> SmallItemIcon;

	UPROPERTY(EditDefaultsOnly, Category="UI Component")
	TSoftObjectPtr<UMaterialInterface> ItemMaterial;

	UPROPERTY(EditDefaultsOnly, Category="UI Component")
	FName MaterialTextureParameter;

};

