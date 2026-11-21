// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortUITypes.h"
#include "AthenaWinnersList.generated.h"

UCLASS(meta=(DisableNativeTick))
class UAthenaWinnersList : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Events")
	void OnWinnersAnnounced(const FAthenaWinnerInfo& WinnerInfo);

	UPROPERTY(BlueprintReadWrite, Category="AthenaWinnersList")
	bool bCanDisplayMultiWinners;

};

