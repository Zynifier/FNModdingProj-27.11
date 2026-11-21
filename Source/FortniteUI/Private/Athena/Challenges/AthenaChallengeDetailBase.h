// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaChallengeDetailBase.generated.h"

class UFortItemBaseWidget;
class USizeBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeDetailBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeDetailBase", meta=(AllowPrivateAccess="TRUE", BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UFortItemBaseWidget> ItemInfo_PreviewedItem;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeDetailBase", meta=(AllowPrivateAccess="TRUE", BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<USizeBox> SB_MainContent;

};

