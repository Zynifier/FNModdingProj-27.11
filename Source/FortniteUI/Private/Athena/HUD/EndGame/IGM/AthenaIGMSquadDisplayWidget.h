// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaIGMSquadDisplayWidget.generated.h"

class UAthenaIGMSquadMemberWidget;
class UDynamicEntryBox;

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UAthenaIGMSquadDisplayWidget : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaIGMSquadMemberWidget> LocalPlayerSquadMemberWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaIGMSquadMemberWidget"))
	TObjectPtr<UDynamicEntryBox> EntryBox_SquadMemberWidgets;

};

