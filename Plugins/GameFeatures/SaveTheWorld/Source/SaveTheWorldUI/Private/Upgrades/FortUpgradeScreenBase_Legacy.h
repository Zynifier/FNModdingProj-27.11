// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "STW/Items/FortHomebaseNodeItemDefinition.h"
#include "FortUpgradeScreenBase_Legacy.generated.h"

class UCommonLoadGuard;
class UCommonTileView;
class UFortItemDefinition;
class UFortTabListWidgetBase_Legacy;
class UFortUpgradeDetailsBase;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortUpgradeScreenBase_Legacy : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="FortUpgradeScreen")
	bool AreUpgradesRespecTokensAvailable() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeScreen")
	bool CanPreview() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeScreen")
	int32 GetUpgradesRespecTokenCount() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeScreen")
	bool IsPreviewing() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortUpgradeScreen")
	void OnPurchaseNodeComplete();

	UFUNCTION(BlueprintImplementableEvent, Category="FortUpgradeScreen")
	void OnUpgradeInfoChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="FortUpgradeScreen")
	void OnUseUpgradesRespecTokenComplete();

	UFUNCTION(BlueprintCallable, Category="FortUpgradeScreen")
	void RefreshFocus();

	UFUNCTION(BlueprintCallable, Category="FortUpgradeScreen")
	void TogglePreview();

	UFUNCTION(BlueprintCallable, Category="FortUpgradeScreen")
	void UseUpgradesRespecToken();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUpgradeScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> UpgradesTabSelector;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUpgradeScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> UpgradesTileView;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUpgradeScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> UpgradeTileViewLoadGuard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUpgradeScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortUpgradeDetailsBase> Details;

	UPROPERTY(EditAnywhere, Category="FortUpgradeScreen")
	TMap<FName, EHomebaseNodeType> TabToNodeTypeMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUpgradeScreen")
	TObjectPtr<UFortItemDefinition> UpgradesRespecToken;

private:
	UFUNCTION()
	void HandleTabSelected(FName TabId);

};

