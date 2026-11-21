// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortExpeditionDetailsWidget.generated.h"

class UFortExpeditionItem;
class UFortItemViewContext_ExpeditionSquadSlotsView;
class UFortSquadSlotsView;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionDetailsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Expedition")
	void RequestAbandonExpedition();

	UFUNCTION(BlueprintCallable, Category="Expedition")
	void SetCurrentSquadId(FName SquadId);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ObjectListItem")
	void SetData(UFortExpeditionItem* InItem);

protected:
	UPROPERTY(BlueprintReadOnly, Category="Item Management|Tile")
	TWeakObjectPtr<UFortExpeditionItem> Item;

	UPROPERTY(BlueprintReadOnly, Export, Category="Expedition", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotsView> ExpeditionSquadSlotsView;

	UPROPERTY(BlueprintReadWrite, Category="Expedition")
	FName CurrentSquadId;

private:
	UFUNCTION()
	void HandleAbandonExpeditionCompleted(const UFortExpeditionItem* Expedition, bool bSuccess);

	UPROPERTY(Instanced)
	TObjectPtr<UFortItemViewContext_ExpeditionSquadSlotsView> ItemViewContext_ExpeditionSlotsView;

};

