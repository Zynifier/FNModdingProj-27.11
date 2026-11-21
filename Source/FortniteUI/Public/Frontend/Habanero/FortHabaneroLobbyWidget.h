// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Frontend/Habanero/FortHabaneroTierWidget.h"
#include "FortHabaneroLobbyWidget.generated.h"

class UCommonButtonBase;
class UFortHabaneroInfoModal;

UCLASS(meta=(DisableNativeTick))
class FORTNITEUI_API UFortHabaneroLobbyWidget : public UFortHabaneroTierWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetBangVisible(const bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateProgressToNextHabanero(int32 UnrealRankPlayerPosition, float ProgressPercent);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHabaneroLobbyWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Info;

private:
	UPROPERTY(EditAnywhere, Category="FortHabaneroLobbyWidget")
	FGameplayTag RankedInfoBangTag;

	UPROPERTY(EditAnywhere, Category="FortHabaneroLobbyWidget", meta=(AllowPrivateAccess))
	TSubclassOf<UFortHabaneroInfoModal> InfoModalClass;

};

