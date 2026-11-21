// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "FortWeakPoint.generated.h"

class AFortWeakPoint;
class UFortWeakPointsCoordinatorComponent;
class UShapeComponent;
enum class EFortWeakPointState : uint8;

UENUM(BlueprintType)
enum class EFortWeakPointState : uint8
{
	Uninitialized = 0,
	Inactive = 1,
	Active = 2,
	Destroyed = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortOnWeakPointStateChanged, AFortWeakPoint*, WeakPoint, EFortWeakPointState, NewState);

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortWeakPoint : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	FName GetWeakPointAttachmentSocketName() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	EFortWeakPointState GetWeakPointState() const;

protected:
	UFUNCTION(BlueprintNativeEvent)
	UShapeComponent* GetAimAssistTargetComponent();

	UFUNCTION()
	void OnRep_WeakPointState();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeakPointStateChanged(EFortWeakPointState CurrentState);

	UPROPERTY(BlueprintAssignable)
	FFortOnWeakPointStateChanged OnWeakPointStateChangedDelegate;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeakPointsCoordinatorComponent> CachedWeakPointCoordinator;

	UPROPERTY(BlueprintGetter=GetWeakPointState, ReplicatedUsing=OnRep_WeakPointState, Category="FortWeakPoint")
	EFortWeakPointState WeakPointState;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetWeakPointAttachmentSocketName, Replicated, Category="FortWeakPoint")
	FName WeakPointAttachmentSocketName;

	UPROPERTY(EditAnywhere, Category="FortWeakPoint")
	bool bShouldDisplayHealthBarWhenActive;

	UPROPERTY(EditAnywhere, Category="FortWeakPoint")
	bool bShouldRegisterForAimAssist;

};

