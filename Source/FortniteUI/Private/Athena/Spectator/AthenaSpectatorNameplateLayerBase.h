// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortHUDElementWidget.h"
#include "AthenaSpectatorNameplateLayerBase.generated.h"

class UAthenaRemotePlayerViewData;
class UAthenaSpectatorNameplateBase;
class UFortActorCanvas;

UCLASS(Abstract)
class UAthenaSpectatorNameplateLayerBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnPlayerDataAdded(UAthenaRemotePlayerViewData* InPlayerData);

protected:
	UPROPERTY(EditAnywhere, Category="AthenaSpectatorNameplateLayerBase")
	TSubclassOf<UAthenaSpectatorNameplateBase> NameplateWidgetClass;

private:
	UFUNCTION()
	void OnArrowTeamColorVisibleChanged(bool bVisible);

	UFUNCTION()
	void OnTeamColorVisibleChanged(bool bVisible);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FUniqueNetIdRepl, TObjectPtr<UAthenaSpectatorNameplateBase>> NameplateWidgetMap;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActorCanvas> Canvas_NameplateIndicators;

};

