// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Map/AthenaQuestCustomMapWidget.h"
#include "AthenaNPCQuestServicesPanel.generated.h"

class UCollectionNPCServiceContainer;
class UObject;

UCLASS()
class FORTNITEUI_API UAthenaNPCQuestServicesPanel : public UAthenaQuestCustomMapWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Show"))
	void BP_Show(const FText& NPCTitle, const TSoftObjectPtr<UObject>& NPCPicture);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCollectionNPCServiceContainer> Services;

};

