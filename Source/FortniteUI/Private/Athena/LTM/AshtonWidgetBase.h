// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "AshtonWidgetBase.generated.h"

class AFortAthenaMutator_Ashton;
enum class EAshtonStoneStateType : uint8;
enum class EAshtonStoneType : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAshtonWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCloseWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStoneChanged(EAshtonStoneType StoneType, EAshtonStoneStateType StoneState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnVillainRespawnCountChanged(int32 NumRespawnsLeft, float RespawnPercentLeft);

protected:
	UFUNCTION()
	void OnStoneListChanged();

	UFUNCTION()
	void OnVillainRespawnsRemainingChanged();

	UFUNCTION()
	void UpdateAllUI(bool bFirstUpdate);

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaMutator_Ashton> AshtonMutatorRef;

};

