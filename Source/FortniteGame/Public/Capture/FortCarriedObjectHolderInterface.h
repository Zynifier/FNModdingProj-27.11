// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortCarriedObjectHolderInterface.generated.h"

class AActor;
class USceneComponent;

USTRUCT()
struct FCarriedObjectAttachmentInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> AttachParent;

	UPROPERTY(Transient)
	FName SocketName;

	UPROPERTY(Transient)
	FVector RelativeTranslation;

	UPROPERTY(Transient)
	FRotator RelativeRotation;

};

UINTERFACE()
class UFortCarriedObjectHolderInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortCarriedObjectHolderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual bool CanHoldObject(AActor* CarriableObject) const;

	UFUNCTION()
	virtual USceneComponent* GetAttachmentComponent(FName SocketName) const;

	UFUNCTION()
	virtual void GetCarriedObjectAttachmentInfo(FCarriedObjectAttachmentInfo& OutAttachInfo) const;

	UFUNCTION()
	virtual void OnCarriedObjectAttach(AActor* AttachedObject);

	UFUNCTION()
	virtual void OnCarriedObjectDetach(AActor* DetachedObject);

};

