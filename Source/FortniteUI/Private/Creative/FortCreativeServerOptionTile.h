// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortCreativeServerOptionTile.generated.h"

class UCommonTextBlock;
class UFortCreativeServerInfo;

UCLASS(BlueprintType, Blueprintable)
class UFortCreativeServerOptionTile : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetBPData(const UFortCreativeServerInfo* ServerInfo);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_JoinServerType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_JoinServerPlayerCount;

	UPROPERTY(Transient)
	TObjectPtr<UFortCreativeServerInfo> Server;

};

