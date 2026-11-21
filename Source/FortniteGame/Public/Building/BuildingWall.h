// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "NavLinkCustomInterface.h"
#include "AI/FortAITypes.h"
#include "AI/NavUtils/ClimbLinkUtils.h"
#include "Building/BuildingSMActor.h"
#include "DoorInterface.h"
#include "FortSoundIndicatorInterface.h"
#include "LockableInterface.h"
#include "OpenableInterface.h"
#include "BuildingWall.generated.h"

class AActor;
class UBoxComponent;
class UFortBuildingWallDoorComponent;
class UFortDoorLinkComponent;
class UFortSoundIndicatorComponent;
class UMaterialInterface;
class UNavArea;
class UPrimitiveComponent;
class USoundBase;
class UStaticMesh;
class UStaticMeshComponent;

UENUM()
enum class EDoorOpenStyle : uint8
{
	Open = 0,
	SlamOpen = 1,
	SmashOpen = 2,
	Close = 3,
};

USTRUCT(BlueprintType)
struct FBuildingWallActorClassData : public FBuildingSMActorClassData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingWallActorClassData)
class ABuildingWall : public ABuildingSMActor, public INavLinkCustomInterface, public ILockableInterface, public IOpenableInterface, public IFortSoundIndicatorInterface, public IDoorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="BuildingWall")
	UFortBuildingWallDoorComponent* GetDoorComponent() const;

	UFUNCTION(BlueprintPure, Category="Door")
	bool HasBashableDoor() const;

	UFUNCTION(BlueprintPure, Category="Door")
	bool HasSlidingDoor() const;

	UFUNCTION(BlueprintPure, Category="Door")
	bool HasSwingingDoor() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="BuildingWall")
	bool IsDoorComponent(const UStaticMeshComponent* MeshComponent) const;

	UFUNCTION(BlueprintPure, Category="Helper")
	bool IsDoorOpen() const;

	UFUNCTION(BlueprintPure, Category="Door")
	bool IsLocked() const;

	UPROPERTY(DuplicateTransient)
	FClimbLinkData ClimbLink;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	TEnumAsByte<EBuildingWallArea::Type> AreaShapeType;

protected:
	UFUNCTION()
	void OnNearDoorTriggerTouched(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnNearDoorTriggerUnTouched(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	virtual void OnRep_bDoorCollisionDisabled();

	UFUNCTION()
	virtual void OnRep_bDoorOpen();

	UFUNCTION()
	void VerifyDoorCollisionMatchesServer();

	UFUNCTION()
	void VerifyDoorOpenMatchesServer();

	UPROPERTY(EditAnywhere, Category="Door")
	TSoftClassPtr<UNavArea> DoorObstacleClass;

	UPROPERTY(EditAnywhere, Category="Door")
	FVector3f DoorScale;

	UPROPERTY(EditAnywhere, Category="Door")
	FVector3f DoorOffset;

	UPROPERTY(EditAnywhere, Category="Door")
	FVector3f SlidingDoorOffset;

	UPROPERTY(EditAnywhere, Category="Door")
	FRotator3f DoorTargetRotationOffset;

	UPROPERTY(EditAnywhere, Category="Door")
	FRotator3f SlidingDoorTargetRotationOffset;

	UPROPERTY(EditAnywhere, Category="Door")
	FRotator3f DoorRotationOffset;

	UPROPERTY(EditAnywhere, Category="Door")
	FRotator3f SlidingDoorRotationOffset;

	UPROPERTY(EditAnywhere, Category="Door")
	FVector3f AutomaticSlidingDoorBoxExtent;

	UPROPERTY(EditAnywhere, Category="Door")
	FVector3f AutomaticSlidingDoorBoxOffset;

	UPROPERTY(EditAnywhere, Category="Door")
	FVector3f SlamOpenDoorBoxExtent;

	UPROPERTY(EditAnywhere, Category="Door")
	float SlidingTranslation;

	UPROPERTY(EditAnywhere, Category="Door")
	float SlidingOpenTime;

	UPROPERTY(EditDefaultsOnly, Category="Door")
	TObjectPtr<USoundBase> DoorOpeningSound;

	UPROPERTY(EditDefaultsOnly, Category="Door")
	TObjectPtr<USoundBase> DoorSlammedOpenSound;

	UPROPERTY(EditDefaultsOnly, Category="Door")
	TObjectPtr<USoundBase> DoorClosingSound;

	UPROPERTY(EditAnywhere, Category="Door")
	TObjectPtr<UMaterialInterface> DoorAnimatingMaterial;

	UPROPERTY(VisibleAnywhere, Transient, DuplicateTransient, Export, Category="Door", meta=(EditInline="true"))
	TObjectPtr<UFortSoundIndicatorComponent> DoorSoundIndicatorComponent;

	UPROPERTY(EditAnywhere, Replicated, Category="Door")
	TObjectPtr<UStaticMesh> DoorMesh;

	UPROPERTY(EditAnywhere, Replicated, Category="Door")
	TObjectPtr<UStaticMesh> DoubleDoorMesh;

	UPROPERTY(Transient, DuplicateTransient, TextExportTransient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBuildingWallDoorComponent> DoorComponent;

	UPROPERTY(Transient, DuplicateTransient, TextExportTransient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBuildingWallDoorComponent> SlidingDoorComponent;

	UPROPERTY(Transient, DuplicateTransient, TextExportTransient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> DoubleDoorComponent;

	UPROPERTY(Transient, DuplicateTransient, TextExportTransient, Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> DoorBoxComponent;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Door | Debug")
	bool bShowDoorBoxComponent;
#endif

	UPROPERTY(EditAnywhere, Category="Door", meta=(EditCondition="bCreateDoorLink"))
	FVector3f DoorLinkOffset;

	UPROPERTY(VisibleAnywhere, Transient, Export, Category="AI", meta=(EditInline="true"))
	TObjectPtr<UFortDoorLinkComponent> DoorSmartLinkComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> DoorBlueprintMeshComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SlidingDoorBlueprintMeshComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> DoubleDoorBlueprintMeshComp;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	FBuildingActorNavArea AreaPatternOverride;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	float AreaWidthOverride;

	UPROPERTY(Transient, Replicated)
	EDoorOpenStyle DoorOpenStyle;

	UPROPERTY(EditAnywhere, Category="Door")
	uint8 bSwingingDoor : 1;

	UPROPERTY(EditAnywhere, Category="Door")
	uint8 bSlidingDoor : 1;

	UPROPERTY(EditAnywhere, Category="Door")
	uint8 bAutomaticSlidingDoor : 1;

	UPROPERTY(EditAnywhere, Category="Door")
	uint8 bDoubleDoor : 1;

	UPROPERTY(EditAnywhere, Category="Door", meta=(DisplayAfter="DoorMesh"))
	uint8 bCreateDoorLink : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bDoorOpen)
	uint8 bDoorOpen : 1;

	UPROPERTY(Transient)
	uint8 bLocalDoorOpen : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bDoorCollisionDisabled)
	uint8 bDoorCollisionDisabled : 1;

	UPROPERTY(Transient)
	uint8 bLocalDoorCollisionDisabled : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	uint8 bOverrideAreaWidth : 1;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	uint8 bCreateClimbLink : 1;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	uint8 bProhibitPassOverLowEndOfTriangleWall : 1;

private:
	UPROPERTY(Transient, Replicated)
	uint8 bFastOpenRequested : 1;

};

