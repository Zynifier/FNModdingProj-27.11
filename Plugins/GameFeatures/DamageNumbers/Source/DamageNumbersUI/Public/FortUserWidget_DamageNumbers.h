// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortUserWidget.h"
#include "FortUserWidget_DamageNumbers.generated.h"

class AActor;
class AFortPlayerPawn;
class UCommonUserWidget_DamageNumbers;
class UDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class DAMAGENUMBERSUI_API UFortUserWidget_DamageNumbers : public UFortUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ClearBinding();

	UFUNCTION(BlueprintCallable)
	void OnDamageDealt(double InDamage, bool bInCritical, bool bInFatal, bool bInShield, AActor* HitActor, FVector HitLocation, FGameplayTagContainer Tags);

	UFUNCTION()
	void OnDamageNumberFinishedAnimating(UCommonUserWidget_DamageNumbers* Widget);

	UFUNCTION(BlueprintCallable)
	void OnPawnSet();

	UFUNCTION()
	void OnShieldBreak(bool bInOverShield);

	UFUNCTION(BlueprintCallable)
	void UpdateBinding();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_DamageNumbers")
	double VerticalShiftForNewDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_DamageNumbers")
	double AccumulationTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUserWidget_DamageNumbers")
	int32 MaxNumberCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_DamageNumbers")
	FVector OffsetFromPawnLocationDBNO;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_DamageNumbers")
	FVector OffsetFromPawnLocation;

	UPROPERTY(BlueprintReadWrite, Category="FortUserWidget_DamageNumbers")
	TObjectPtr<AFortPlayerPawn> BoundPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_DamageNumbers")
	FGameplayTag HideDamageNumbersTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_DamageNumbers")
	FGameplayTag DamageAtLocTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUserWidget_DamageNumbers")
	FGameplayTagContainer TagsToNotDisplayDmgNumbersOnSpecificActors;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortUserWidget_DamageNumbers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Numbers;

	UPROPERTY(EditAnywhere, Category="FortUserWidget_DamageNumbers")
	FGameplayTag DamageCueEMPTag;

private:
	UPROPERTY(EditAnywhere, Category="FortUserWidget_DamageNumbers")
	bool bPrecreateDamageNumberEntries;

};

