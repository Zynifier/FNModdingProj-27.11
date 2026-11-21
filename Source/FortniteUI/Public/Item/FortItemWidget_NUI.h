// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "FortItemWidget_NUI.generated.h"

class IFortItemViewContextInterface;
class UFortItem;
class UFortItemDefinition;

UCLASS(Abstract, BlueprintType)
class FORTNITEUI_API UFortItemWidget_NUI : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Widget")
	void SetItemToRepresent(const UFortItem* ItemToRepresent);

	UFUNCTION(BlueprintCallable, Category="Item Widget")
	void SetItemViewContext(TScriptInterface<IFortItemViewContextInterface> ItemViewContext);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemWidget_NUI")
	TSoftObjectPtr<UFortItemDefinition> DesignTimePreviewItemType;
#endif

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortItemWidget_NUI", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(BlueprintReadOnly, Category="FortItemWidget_NUI", meta=(ExposeOnSpawn))
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UFortItem> DesignTimePreviewItem;
#endif

};

