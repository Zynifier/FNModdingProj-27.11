// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/NamedSlotInterface.h"
#include "Components/Widget.h"
#include "AthenaMapLayer.generated.h"

class ULocalPlayer;
class UWidget;

UCLASS()
class UAthenaMapLayer : public UWidget, public INamedSlotInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearTouches();

	UFUNCTION(BlueprintCallable)
	void FlashPlayerIcon();

	UFUNCTION(BlueprintCallable)
	void SetLocalPlayer(ULocalPlayer* LocalPlayer);

	virtual void GetSlotNames(TArray<FName>& SlotNames) const override;

	virtual UWidget* GetContentForSlot(FName SlotName) const override;

	virtual void SetContentForSlot(FName SlotName, UWidget* Content) override;

protected:
	UPROPERTY(Transient)
	TObjectPtr<ULocalPlayer> LocalPlayer;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> QuestContent;

};

